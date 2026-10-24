.setcpu "65816"
.segment "CODE"
.org $B1CE
map_control_0db1ce:
    .byte $E5 ; previous-row copy count
