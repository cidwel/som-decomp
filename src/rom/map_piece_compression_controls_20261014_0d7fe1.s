.setcpu "65816"
.segment "CODE"
.org $7FE1
map_control_0d7fe1:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
