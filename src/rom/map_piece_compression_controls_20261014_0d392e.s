.setcpu "65816"
.segment "CODE"
.org $392E
map_control_0d392e:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E3 ; previous-row copy count
