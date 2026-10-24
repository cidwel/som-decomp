.setcpu "65816"
.segment "CODE"
.org $13BE
map_control_0c13be:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
