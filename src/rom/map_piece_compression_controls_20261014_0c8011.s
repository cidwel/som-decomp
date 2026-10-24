.setcpu "65816"
.segment "CODE"
.org $8011
map_control_0c8011:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
