.setcpu "65816"
.segment "CODE"
.org $F75B
map_control_0df75b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
