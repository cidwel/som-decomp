.setcpu "65816"
.segment "CODE"
.org $FFEB
map_control_0dffeb:
    .byte $E2 ; previous-row copy count
