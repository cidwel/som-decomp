.setcpu "65816"
.segment "CODE"
.org $A05B
map_control_0fa05b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
