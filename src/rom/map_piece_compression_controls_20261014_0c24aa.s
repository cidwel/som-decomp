.setcpu "65816"
.segment "CODE"
.org $24AA
map_control_0c24aa:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
