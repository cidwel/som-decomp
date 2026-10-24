.setcpu "65816"
.segment "CODE"
.org $161C
map_control_0e161c:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
