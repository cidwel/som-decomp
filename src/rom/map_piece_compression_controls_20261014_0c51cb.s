.setcpu "65816"
.segment "CODE"
.org $51CB
map_control_0c51cb:
    .byte $E1 ; previous-row copy count
