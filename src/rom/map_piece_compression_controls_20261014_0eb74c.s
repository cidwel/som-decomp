.setcpu "65816"
.segment "CODE"
.org $B74C
map_control_0eb74c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
