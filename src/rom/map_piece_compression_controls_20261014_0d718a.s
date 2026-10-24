.setcpu "65816"
.segment "CODE"
.org $718A
map_control_0d718a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
