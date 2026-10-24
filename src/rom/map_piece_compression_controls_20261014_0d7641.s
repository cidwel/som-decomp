.setcpu "65816"
.segment "CODE"
.org $7641
map_control_0d7641:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $56 ; distance low bit/count
