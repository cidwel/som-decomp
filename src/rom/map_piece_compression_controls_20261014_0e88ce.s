.setcpu "65816"
.segment "CODE"
.org $88CE
map_control_0e88ce:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
