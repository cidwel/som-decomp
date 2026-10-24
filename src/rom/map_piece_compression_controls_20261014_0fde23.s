.setcpu "65816"
.segment "CODE"
.org $DE23
map_control_0fde23:
    .byte $E3 ; previous-row copy count
