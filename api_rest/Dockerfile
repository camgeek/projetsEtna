FROM debian:latest

RUN DEBIAN_FRONTEND=noninteractive

RUN apt-get update

RUN echo "mysql-server mysql-server/root_password password root" | debconf-set-selections
RUN echo "mysql-server mysql-server/root_password_again password root" | debconf-set-selections
RUN apt-get install -y mysql-server mysql-client

COPY ./bdd.sql $APP_HOME
RUN service mysql start && mysql -uroot -proot -e "CREATE DATABASE API_DB" \
&& sleep 5 && \
mysql -uroot -proot API_DB < bdd.sql

RUN apt-get install -y apache2
RUN apt-get install -y php5 php5-mysql libapache2-mod-php5 php5-mcrypt php5-json
ADD ./api-rest_camille /var/www/api-rest_camille
COPY ./000-default.conf /etc/apache2/sites-available/000-default.conf
COPY ./ports.conf /etc/apache2/ports.conf
COPY ./php.ini /etc/php5/cli/php.ini
RUN a2enmod rewrite

RUN service apache2 restart
ENV PORT 3000
EXPOSE 3000
 
CMD service mysql start && service apache2 start && tail -F /var/log/mysql/error.log
