.setcpu "65816"
.segment "CODE"
.org $58AF
map_control_0f58af:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
