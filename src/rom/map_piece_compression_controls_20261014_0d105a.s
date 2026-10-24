.setcpu "65816"
.segment "CODE"
.org $105A
map_control_0d105a:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
