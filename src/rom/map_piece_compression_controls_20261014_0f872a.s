.setcpu "65816"
.segment "CODE"
.org $872A
map_control_0f872a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
