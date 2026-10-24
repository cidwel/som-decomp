.setcpu "65816"
.segment "CODE"
.org $D198
map_control_0fd198:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
