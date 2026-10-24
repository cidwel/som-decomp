.setcpu "65816"
.segment "CODE"
.org $93DC
map_control_0d93dc:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
