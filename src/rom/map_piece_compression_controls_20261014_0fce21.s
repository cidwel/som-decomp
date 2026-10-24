.setcpu "65816"
.segment "CODE"
.org $CE21
map_control_0fce21:
    .byte $E1 ; previous-row copy count
