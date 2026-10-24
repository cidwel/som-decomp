.setcpu "65816"
.segment "CODE"
.org $508E
map_control_0f508e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
