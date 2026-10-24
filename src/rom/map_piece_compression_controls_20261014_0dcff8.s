.setcpu "65816"
.segment "CODE"
.org $CFF8
map_control_0dcff8:
    .byte $E3 ; previous-row copy count
