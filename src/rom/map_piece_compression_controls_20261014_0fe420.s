.setcpu "65816"
.segment "CODE"
.org $E420
map_control_0fe420:
    .byte $E1 ; previous-row copy count
