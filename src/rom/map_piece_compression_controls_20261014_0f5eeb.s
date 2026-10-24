.setcpu "65816"
.segment "CODE"
.org $5EEB
map_control_0f5eeb:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
