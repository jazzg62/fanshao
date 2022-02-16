export function xflx(val) {
    if (val == 'POS_YF') {
        $res = 'POS机银行卡';
    }
    elseif(val == 'POS_QLB') {
        $res = 'POS机企联币';
    }
    elseif(val == 'POS_CZ') {
        $res = 'POS机充值消费';
    }
    elseif(val == 'SM_WXPAY') {
        $res = '扫码微信支付';
    }
    elseif(val == 'SM_ALIPAY') {
        $res = '扫码支付宝支付';
    }
    elseif(val == 'SM_QLB') {
        $res = '扫码红包支付';
    }
    elseif(val == 'XSWX') {
        $res = '线上微信支付';
    }
    elseif(val == 'XSZFB') {
        $res = '外部平台';
    }
    elseif(val == 'SM_CZ') {
        $res = '充值支付';
    }
    elseif(val == 'XSQLB') {
        $res = '线上红包';
    }
    elseif(val == 'GD_PAY') {
        $res = '动态股东支付';
    }
    elseif(val = 'JFPAY') {
        $res = '积分兑换';
    }
    return $res;
}