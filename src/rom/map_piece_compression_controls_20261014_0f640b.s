.setcpu "65816"
.segment "CODE"
.org $640B
map_control_0f640b:
    .byte $E5 ; previous-row copy count
