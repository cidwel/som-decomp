.setcpu "65816"
.segment "CODE"
.org $7667
map_control_0d7667:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
