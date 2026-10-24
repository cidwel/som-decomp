.setcpu "65816"
.segment "CODE"
.org $1BDD
map_control_0f1bdd:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $D9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
