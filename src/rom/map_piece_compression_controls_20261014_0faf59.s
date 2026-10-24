.setcpu "65816"
.segment "CODE"
.org $AF59
map_control_0faf59:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
