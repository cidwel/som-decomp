.setcpu "65816"
.segment "CODE"
.org $9332
map_control_0d9332:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $49 ; row-distance/count
