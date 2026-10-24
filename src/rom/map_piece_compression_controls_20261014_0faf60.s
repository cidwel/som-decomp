.setcpu "65816"
.segment "CODE"
.org $AF60
map_control_0faf60:
    .byte $E2 ; previous-row copy count
