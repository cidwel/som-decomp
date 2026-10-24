.setcpu "65816"
.segment "CODE"
.org $157B
map_control_0f157b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
