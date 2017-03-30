   <div class="container">

    <form method='POST' action='index.php?choix=c_gest_table&action=addstruct' class="form-horizontal">
      <fieldset>

        <!-- Form Name -->
        <legend>Ajouter une structure</legend>

        <!-- Text input-->
        <div class="control-group">
          <label class="control-label" for="nom">Nom</label>
          <div class="form-group">
            <input id="nom" name="nom" type="text" placeholder="nom" class="form-control" required="">
            
          </div>
        </div>

        <!-- Select Basic -->
        <div class="control-group">
          <label class="control-label" for="type">Type</label>
          <div class="form-group">
            <select id="type" name="type" class="form-control">
              <option>INT</option>
              <option>VARCHAR</option>
              <option>DATE</option>
              <option>TEXT</option>
            </select>
          </div>
        </div>

        <!-- Text input-->
        <div class="control-group">
          <label class="control-label" for="taille">Taille/Valeurs</label>
          <div class="form-group">
            <input id="taille" name="taille" type="text" placeholder="Taille/Valeurs" class="form-control" required="">
            
          </div>
        </div>

        <!-- Select Basic -->
        <div class="control-group">
          <label class="control-label" for="attribut">Attribut</label>
          <div class="form-group">
            <select id="attribut" name="attribut" class="form-control">
              <option>__</option>
              <option>BINARY</option>
              <option>UNSIGNED</option>
              <option>UNSIGNED ZEROFILL</option>
            </select>
          </div>
        </div>

        <!-- Multiple Checkboxes -->
        <div class="control-group">
          <label class="control-label" for="Null"></label>
            <label class="checkbox" for="Null-0">
              <input type="checkbox" name="null" id="null" value="null" class="form-check-input">
              Null
            </label>
        </div>

        <!-- Select Basic -->
        <div class="control-group">
          <label class="control-label" for="Index">Index</label>
          <div class="form-group">
            <select id="index" name="index" class="form-control">
              <option>___</option>
              <option>PRIMARY</option>
              <option>UNIQUE</option>
              <option>INDEX</option>
              <option>FULLTEXT</option>
              <option>SPATIAL</option>
            </select>
          </div>
        </div>

        <!-- Multiple Checkboxes (inline) -->
        <div class="control-group">
          <label class="control-label" for="ai"></label>
            <label class="checkbox inline" for="ai-0">
              <input type="checkbox" name="ai" id="ai-0" value="Auto_incremente" class="form-check-input">
              Auto_incremente
            </label>
        </div>
        <input type='submit' value='Valider' name='valider'>
      </fieldset>
    </form>
