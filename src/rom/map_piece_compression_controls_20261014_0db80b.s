.setcpu "65816"
.segment "CODE"
.org $B80B
map_control_0db80b:
    .byte $E2 ; previous-row copy count
