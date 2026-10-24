.setcpu "65816"
.segment "CODE"
.org $873C
map_control_0f873c:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
