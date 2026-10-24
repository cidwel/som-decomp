.setcpu "65816"
.segment "CODE"
.org $895A
map_control_0e895a:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
