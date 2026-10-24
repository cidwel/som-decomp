.setcpu "65816"
.segment "CODE"
.org $7BE7
map_control_0c7be7:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
