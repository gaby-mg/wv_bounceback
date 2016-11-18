<?php
/**
 * @file
 * wv_bounceback.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function wv_bounceback_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_imagen_interior_front_end_'.
  $field_bases['field_imagen_interior_front_end_'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_imagen_interior_front_end_',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_imagen_portada_front_end_'.
  $field_bases['field_imagen_portada_front_end_'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_imagen_portada_front_end_',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_imagen_trasera_front_end_'.
  $field_bases['field_imagen_trasera_front_end_'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_imagen_trasera_front_end_',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_wv_bb_predet_texts'.
  $field_bases['field_wv_bb_predet_texts'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wv_bb_predet_texts',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'La Navidad en España es una fecha muy señalada en la que compartimos buenos momentos con la familia y amigos. Nos reunimos a comer algo especial, nos reímos e incluso cantamos canciones típicas. ¿Cómo celebráis la Navidad en tu país? Te mando un abrazo y mis mejores deseos para el próximo año.',
        2 => 'Con esta felicitación me gustaría desearte unas felices fiestas y un muy feliz año nuevo. Espero que celebres estas fechas rodeado de tu familia y amigos. ¡Un abrazo muy fuerte desde España y feliz Navidad!',
        3 => '¡Feliz Navidad y próspero Año Nuevo! Te mando esta felicitación navideña con mis mejores deseos para ti y tu familia. Espero que el año que viene os traiga felicidad y salud para todos vosotros. Un saludo de tu padrino en España.',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_wv_bounceback_reference'.
  $field_bases['field_wv_bounceback_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wv_bounceback_reference',
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_product_reference',
    'settings' => array(
      'options_list_limit' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'commerce_product_reference',
  );

  // Exported field_base: 'field_wv_bounceback_text'.
  $field_bases['field_wv_bounceback_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wv_bounceback_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
