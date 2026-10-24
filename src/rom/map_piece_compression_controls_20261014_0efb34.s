.setcpu "65816"
.segment "CODE"
.org $FB34
map_control_0efb34:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
