.setcpu "65816"
.segment "CODE"
.org $E014
map_control_0de014:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
