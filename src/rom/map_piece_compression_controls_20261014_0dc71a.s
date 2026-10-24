.setcpu "65816"
.segment "CODE"
.org $C71A
map_control_0dc71a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
