.setcpu "65816"
.segment "CODE"
.org $B056
map_control_0db056:
    .byte $E2 ; previous-row copy count
