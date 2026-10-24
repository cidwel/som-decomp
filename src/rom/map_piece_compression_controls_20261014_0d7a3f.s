.setcpu "65816"
.segment "CODE"
.org $7A3F
map_control_0d7a3f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
