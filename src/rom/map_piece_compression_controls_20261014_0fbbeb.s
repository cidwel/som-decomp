.setcpu "65816"
.segment "CODE"
.org $BBEB
map_control_0fbbeb:
    .byte $E1 ; previous-row copy count
