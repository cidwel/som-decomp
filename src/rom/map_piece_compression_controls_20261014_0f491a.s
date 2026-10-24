.setcpu "65816"
.segment "CODE"
.org $491A
map_control_0f491a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
