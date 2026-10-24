.setcpu "65816"
.segment "CODE"
.org $8743
map_control_0e8743:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
