.setcpu "65816"
.segment "CODE"
.org $FF94
map_control_0dff94:
    .byte $E1 ; previous-row copy count
