.setcpu "65816"
.segment "CODE"
.org $35DB
map_control_0c35db:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
