.setcpu "65816"
.segment "CODE"
.org $B4EE
map_control_0db4ee:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
