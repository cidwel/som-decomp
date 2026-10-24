.setcpu "65816"
.segment "CODE"
.org $8282
map_control_0f8282:
    .byte $E1 ; previous-row copy count
