.setcpu "65816"
.segment "CODE"
.org $8BBD
map_control_0f8bbd:
    .byte $E1 ; previous-row copy count
