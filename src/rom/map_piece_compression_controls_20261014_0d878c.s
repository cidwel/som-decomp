.setcpu "65816"
.segment "CODE"
.org $878C
map_control_0d878c:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
