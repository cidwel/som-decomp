.setcpu "65816"
.segment "CODE"
.org $6BED
map_control_0f6bed:
    .byte $E1 ; previous-row copy count
