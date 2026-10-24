.setcpu "65816"
.segment "CODE"
.org $EE47
map_control_0eee47:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
