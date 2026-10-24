.setcpu "65816"
.segment "CODE"
.org $863E
map_control_0c863e:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
