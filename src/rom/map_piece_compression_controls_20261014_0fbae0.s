.setcpu "65816"
.segment "CODE"
.org $BAE0
map_control_0fbae0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
