.setcpu "65816"
.segment "CODE"
.org $CA0F
map_control_0eca0f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
